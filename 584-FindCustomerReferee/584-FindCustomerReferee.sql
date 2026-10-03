-- Last updated: 10/3/2026, 6:53:41 PM
# Write your MySQL query statement below
select name
from Customer
where referee_id IS NULL OR referee_id != 2;
