-- Last updated: 10/3/2026, 6:50:33 PM
# Write your MySQL query statement below
select product_id
from Products
where low_fats = 'Y' and recyclable = 'Y'
group by product_id

