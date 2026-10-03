-- Last updated: 10/3/2026, 6:50:38 PM
# Write your MySQL query statement below
select
        m.employee_id ,
        m.name  , 
        COUNT(e.reports_to)as reports_count ,
        ROUND((AVG(e.age)),0)as average_age 
from Employees m
join  Employees e
        on e.reports_to = m.employee_id
group by m.employee_id
order by 
    m.employee_id

