-- Last updated: 10/3/2026, 6:53:44 PM
# Write your MySQL query statement below
select e.name, b.bonus
from Employee e 
left join Bonus b
        on e.empId = b.empId
where b.bonus IS NULL OR b.bonus < 1000