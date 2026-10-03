-- Last updated: 10/3/2026, 6:51:45 PM
# Write your MySQL query statement below
select
    product_id,
    new_price as price
from Products
where (product_id, change_date) IN(
select
    product_id,
    MAX(change_date)
    from Products
    where change_date <= '2019-08-16'
    group by product_id
)

UNION

select
    product_id,
    10 as price
from Products
group by product_id
having MIN(change_date) > '2019-08-16'
