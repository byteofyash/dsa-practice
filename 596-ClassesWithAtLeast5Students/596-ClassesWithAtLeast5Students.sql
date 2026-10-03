-- Last updated: 10/3/2026, 6:53:30 PM
# Write your MySQL query statement below
select 
    class
from Courses
group by class
having COUNT(student) >=5
