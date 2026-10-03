-- Last updated: 10/3/2026, 6:53:25 PM
# Write your MySQL query statement below
with freq1Data as (
    select 
        num
    from MyNumbers
    group by num
    having COUNT(num) = 1
) 

select
    MAX(num) as num
from freq1Data


   