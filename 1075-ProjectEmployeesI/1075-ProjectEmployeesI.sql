-- Last updated: 10/3/2026, 6:52:17 PM
# Write your MySQL query statement below
select p.project_id, 
    ROUND(AVG(e.experience_years), 2) AS average_years
from Project p
LEFT JOIN Employee e
           ON p.employee_id = e.employee_id
GROUP by p.project_id
