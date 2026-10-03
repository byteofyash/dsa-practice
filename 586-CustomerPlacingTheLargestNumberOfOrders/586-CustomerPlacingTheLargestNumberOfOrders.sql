-- Last updated: 10/3/2026, 6:53:36 PM
# Write your MySQL query statement below
select
customer_number
from Orders
group by customer_number
order by COUNT(order_number) DESC 
LIMIT 1