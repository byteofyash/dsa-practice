-- Last updated: 10/3/2026, 6:53:22 PM
# Write your MySQL query statement below
select *
from Cinema
where description != 'boring' AND id%2 !=0
order by
 rating DESC