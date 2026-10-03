-- Last updated: 10/3/2026, 6:51:33 PM
# Write your MySQL query statement below
with BoardingQueue as(
    select 
    person_name,
    turn,
    SUM(weight) OVER(ORDER by turn ASC) as running_weight
    from Queue
)

select person_name
from BoardingQueue
where running_weight <=1000

order by 
    turn DESC
    LIMIT 1

