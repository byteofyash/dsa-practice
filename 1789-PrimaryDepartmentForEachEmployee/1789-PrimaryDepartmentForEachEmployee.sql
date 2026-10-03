-- Last updated: 10/3/2026, 6:50:30 PM
# Write your MySQL query statement below
select 
        employee_id ,
        department_id
from Employee 
where primary_flag = 'Y' 

UNION

select
    employee_id ,
     department_id
from Employee 
group by employee_id 
having COUNT(department_id) = 1


