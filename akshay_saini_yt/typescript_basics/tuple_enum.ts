/* 
a tuple works like array with some additional considerations
The numner of elements in the tuple is fixed
the types of elements are known and need not to be same
*/
let skill: [string, number];

skill = ["Programming", 6];

//we use tuple to define colors RGB (r,g,b)
let color: [number, number, number] = [255, 0, 0];

//Optional tuple Elements
//a tuple can have optional elementsspecified using question mark? postfix
//e.g. we can deifne a RGBA tuple with optional alpha channel
let bgColor, headerColor: [number, number, number, number?];

bgColor = [0, 255, 255, 0.5];
headerColor = [0, 255, 255];

/* An ENUM is a group of named constantvalues.
    Enum stands for enumerated type
*/

enum Days {
  Mon,
  Tue,
  Wed,
  Thr,
  Fri,
  Sat,
  Sun,
}

function isItSunday(day: Days) {
  let isSunday: boolean;
  switch (day) {
    case Days.Mon:
      console.log("Monday");
      break;
    case Days.Tue:
      console.log("Tuesday");
      break;
    case Days.Wed:
      console.log("Wednesday");
      break;
    case Days.Thr:
      console.log("Thrusday");
      break;
    case Days.Fri:
      console.log("fRIDAY");
    default:
      console.log("weekend");
  }
}

enum Day {
  Mon = 1,
  Tue,
  Wed,
  Thr,
  Fri,
  Sat,
  Sun,
}

function isItSun(day: Days) {
  let isSunday: boolean;
  switch (day) {
    case Days.Mon:
      console.log("Monday");
      break;
    case Days.Tue:
      console.log("Tuesday");
      break;
    case Days.Wed:
      console.log("Wednesday");
      break;
    case Days.Thr:
      console.log("Thrusday");
      break;
    case Days.Fri:
      console.log("fRIDAY");
    default:
      console.log("weekend");
  }
}

enum ApprovedStatus {
  draft,
  submitted,
  approved,
  rejected,
}

const request = {
  id: 1,
  status: ApprovedStatus.approved,
  description: "Please aprove this request",
};

if (request.status == ApprovedStatus.approved) {
  console.log("Send for pproval");
}
