-- Last updated: 10/3/2026, 6:53:48 PM
# Write your MySQL query statement below
select m.name
from Employee m 
INNER JOIN Employee e
        on m.id = e.managerId 
GROUP BY m.id
HAVING COUNT(e.id) >= 5
