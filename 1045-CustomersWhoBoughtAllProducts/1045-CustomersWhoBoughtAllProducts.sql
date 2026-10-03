-- Last updated: 10/3/2026, 6:52:22 PM
# Write your MySQL query statement below
select
  c.customer_id
from Customer c
left join Product p
        on c.product_key = p.product_key
group by c.customer_id
having COUNT(distinct c.product_key) = (SELECT COUNT(distinct  product_key) from Product)