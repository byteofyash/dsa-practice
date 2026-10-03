-- Last updated: 10/3/2026, 6:51:11 PM
# Write your MySQL query statement below
select unique_id, name
from Employees e  
LEFT JOIN EmployeeUNI eu
        ON e.id = eu.id



