-- Last updated: 10/3/2026, 6:55:02 PM
# Write your MySQL query statement below
select
e.name as Employee,
e.salary as Salary,
d.name as Department
from Employee e
inner join Department d
        on e.departmentId = d.id
where(e.departmentId, e.salary) IN (
    select
    departmentId,
    MAX(salary)
    from Employee
    group by departmentId
)

