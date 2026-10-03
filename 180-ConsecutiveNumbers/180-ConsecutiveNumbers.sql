-- Last updated: 10/3/2026, 6:55:04 PM
# Write your MySQL query statement below
WITH LookAhead as (

select 
    num,
    LEAD(num,1) OVER(ORDER BY id) as next_num,
    LEAD(num,2) OVER(ORDER BY id) as next_next_num
from Logs
)

select 
    DISTINCT num as ConsecutiveNUms
FROM LookAhead
where num = next_num 
    and num = next_next_num

