stackoverflow

Users can post questions, answer questions, and comment on questions and answers.
Users can vote on questions and answers.
Questions should have tags associated with them.
Users can search for questions based on keywords, tags, or user profiles.
The system should assign reputation score to users based on their activity and the quality of their contributions.
The system should handle concurrent access and ensure data consistency.

---

so enities question, answers, comment, users

A question can have muliple answers

so questions and answer can have multple comments

and each question have a upvote/downvote count

users have something reputation, inrease with increase in upvotes of his question/answers

---

User
id
reputation

Question
id,
userId,
list<Answers>,
list<comments>
list<tags>
votes
accepted answer
body

Answer
id,
userId,
list<comments>
votes
body

Comments
id
userId
body

Tags
string

observer design pattern , users will observe question and answers they post,
so on each upvote/downvote users reputation got change

strategy in finding questions, so 3 strategy keyword based, tags, user profile based
