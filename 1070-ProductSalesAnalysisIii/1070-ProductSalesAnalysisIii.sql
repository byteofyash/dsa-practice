-- Last updated: 10/3/2026, 6:52:19 PM
# Write your MySQL query statement below
select
 product_id, 
 year as first_year ,
quantity ,price 
from Sales
where (product_id, year) IN (
    select
     product_id,
    MIN(year)
    from Sales
    group by product_id
)
