-- Last updated: 10/3/2026, 6:54:55 PM
# Write your MySQL query statement below
select w2.id
from Weather w2
inner join Weather w1
          on DATEDIFF(w2.recordDate, w1.recordDate) = 1
where w2.temperature > w1.temperature
