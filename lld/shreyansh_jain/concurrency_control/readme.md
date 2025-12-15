System Design : Distributed Concurrency Control

in HLD interviewer ask directly about distributed concurrency control

in LLD , interviewer generally ask for parking slot or bookMyShow

Scenario : Many concurrent request tries to book the same same theatre seat

user 1, user 2 , user 3 -> [ 10 , free] {id, statud}

CRITICAL SECTION : a piece of logic where we are trying to access a shared resource

{
Read Seat Row with ID: 10
if Free:
logic to change status from free to book
Update in DB
}

multiple request try to access this code logic

in interview we use SYNCHRONIZED for Critical Section, it internally put lock on this

synchronized(){
Read Seat Row with id:10
if Free:
.......
}

here first request came and put lock, and update status , when second request came to this section it found status BOOK

, but in distributed system , it won't work as 2 request came to 2 different machine

process and threads
one process can have mulitple thread, synchronized works on single process

2-----------
using Distributed Concurrency Control

Many time we say optimistic locking or pessimistic locking , it is wrong to say that

we have to say OPtimistic as Concurrency Control , Pessimistic as Concurrency Control

                    Distributed Concurrency Control
    Optimistic Concurrency Control          Pessimistic Concurrency Control

Before we know above terms we must know these terms

What is usage of Transaction
-- transaction help to achieve integrity, means it help us to avoid INCONSISTENCY in our database
e.g.
Debit Money from A and credit money to B

BEGIN_TRANSACTION: - debit money from A - credit money to B
if all success:
Commit
else:
ROLLBACK
END_TRANSACTION

What is DB Locking
Db locking helps to make sure that no other transaction update the locked row

---

|Lock Type | Another shared lock | Another Excludive Lock |
|Have Share Lock (S) | yes | no |
|Have Exclusive Lock (X) | no | yes |

---

Share lock is known as read lock
T1(S) [10,Free]
T2(S) read can happen

What is Isolation Level present
how much level of concurrency is allowed
in general there are multiple transaction, but each transaction is distinct

---

| Isolation level | Dirty Read Possible | Non-Repeatable Read Possible | Phantom Read Possible |
| **********************************************\_**********************************************|\_
| Read uncommited | Y | Y | Y |
| Read commited | N | Y | Y |
| Repeatable Read | N | N | N |
| Serializable | N | N | N |

---
