# Parking Lot LLD - AI Coding Agent Instructions

## Project Overview

This is an **interview practice repository** for low-level design (LLD) of a parking lot system. It contains **three separate implementations** exploring different approaches to the same design problem:

- `GetSdeReady/ParkingLot/` - Main implementation (most complete)
- `GetSdeReady/LLD-of-Parking-Lot-by-GET-SDE-READY-main/` - Reference implementation with `com.demo` package structure
- `GetSdeReady/JavaDoubts/` - Experimental code for testing Java reflection with enums

**Important**: These are independent implementations. Changes to one do not affect the others. Verify which implementation the user is referring to before making changes.

## Architecture & Core Patterns

### 1. Singleton Pattern for Shared State

- **ParkingLot** and **DisplayBoard** use eager/lazy singleton initialization
- Example: `ParkingLot.getInstance()` returns the single parking lot instance
- All services share the same ParkingLot instance to maintain consistent state

### 2. Strategy Pattern for Parking Allocation

- Interface: `ParkingStrategy.findParkingSpot(ParkingSpotEnum)`
- Implementations:
  - `NearestFirstParkingStrategy` - Returns first available spot (index 0)
  - `FarthestFirstParkingStrategy` - Returns last available spot
- Strategy is injected into `ParkingServiceImpl` constructor
- Example: `new ParkingServiceImpl(new FarthestFirstParkingStrategy())`

### 3. Observer Pattern for Display Board Updates

- `DisplayServiceImpl` implements `Observer` interface
- Observers receive `ParkingEvent` notifications on entry/exit
- Pattern: `notifyObservers(event)` → `observer.update(event)` → DisplayBoard updates
- Critical: DisplayBoard updates are event-driven, not polled

### 4. Thread-Safe Spot Allocation

```java
synchronized(parkingSpot) {
    if(parkingSpot.isFree()) {
        parkingSpot.setFree(false);
        // update lists atomically
    }
}
```

- Double-check locking prevents race conditions during concurrent entry
- ParkingSpot uses `AtomicInteger` for unique ID generation

## Package Structure & Naming Conventions

### Main Implementation (`GetSdeReady/ParkingLot/`)

- **No package declarations** - all classes are in default package
- Imports use simple names: `import dto.*;` not `import com.demo.dto.*;`
- Structure:
  - `dto/` - Data objects (ParkingLot, ParkingTicket, EntrancePanel, etc.)
  - `dto/parkingSpot/` - ParkingSpot hierarchy (Mini, Compact, Large)
  - `dto/vehicle/` - Vehicle hierarchy (Motorbike, Car, Truck)
  - `dto/account/` - User roles (Account, Admin, ParkingAttendent)
  - `enums/` - ParkingSpotEnum, ParkingEventType
  - `interfaces/` - Service contracts
  - `services/` - Service implementations
  - `parkingStrategy/` - Strategy implementations
  - `paymentMethod/` - Payment abstractions

### Reference Implementation (`LLD-of-Parking-Lot-by-GET-SDE-READY-main/`)

- Uses package structure: `com.demo.dto`, `com.demo.services`, etc.
- Includes additional features: `addWash()`, `cost()` calculation

## Key Data Flows

### Vehicle Entry Flow

1. `Main.java` creates vehicle and calls `parkingLotServices.entry(vehicle)`
2. `ParkingServiceImpl.entry()` gets vehicle's required spot type
3. Strategy finds appropriate free spot from `ParkingLot.getFreeParkingSpots()`
4. Thread-safe spot allocation (synchronized block)
5. Spot moved from free → occupied lists
6. ParkingTicket created with vehicle + spot
7. ParkingEvent fired → DisplayBoard updated via Observer

### Vehicle Exit Flow

1. `exit(parkingTicket, vehicle)` validates ticket matches vehicle
2. Calculates parking amount from spot
3. Spot moved from occupied → free lists
4. ParkingEvent fired → DisplayBoard updated
5. Returns payment amount

## Critical Implementation Details

### ParkingLot State Management

```java
Map<ParkingSpotEnum, List<ParkingSpot>> freeParkingSpots;
Map<ParkingSpotEnum, List<ParkingSpot>> occupiedParkingSpots;
```

- Each enum type (MINI, COMPACT, LARGE) has separate free/occupied lists
- Lists are initialized in constructor, never null
- Direct list manipulation (add/remove) during entry/exit

### Vehicle to Spot Mapping

- Motorbike → MINI spots
- Car → COMPACT spots
- Truck → LARGE spots
- Mapping via `vehicle.getParkingSpotEnum()` method

### Exception Handling

- `SpotNotFoundException` - thrown when no spots available for requested type
- `InvalidTicketException` - thrown when ticket doesn't match vehicle at exit
- Both are custom exceptions in `exceptions/` package

## Development Workflow

### Running the Application

- Entry point: `Main.java` in each implementation
- No build tool configuration (Maven/Gradle) - plain Java
- Uses JDK 11+
- Run via IDE or: `java Main`

### Testing Approach

- Manual testing via Main.java scenarios
- No JUnit tests present
- Common test pattern:
  1. Create parking spots via `ParkingSpotService`
  2. Create vehicles
  3. Test entry/exit flows
  4. Verify ticket generation and payment

### Adding New Features

When adding features (e.g., car wash, electric charging):

1. Extend `ParkingTicket` to track services
2. Add service methods to `ParkingServiceImpl`
3. Update payment calculation in `exit()`
4. Consider adding new ParkingEventType if display needs updating

## Common Mistakes to Avoid

- ❌ Don't add package declarations to `GetSdeReady/ParkingLot/` classes
- ❌ Don't mix implementations - they're separate learning exercises
- ❌ Don't modify free/occupied lists without synchronized access
- ❌ Don't create multiple ParkingLot instances - breaks singleton pattern
- ❌ Don't forget to register observers before triggering events

## Design Principles in Action

- **Open/Closed**: New parking strategies without modifying service
- **Dependency Inversion**: Services depend on interfaces, not concrete classes
- **Single Responsibility**: Separate services for parking, payment, display
- **Factory Pattern**: `ParkingSpotService.create()` creates spots by enum type
