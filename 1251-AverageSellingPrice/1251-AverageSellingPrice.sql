-- Last updated: 10/3/2026, 6:51:26 PM
# Write your MySQL query statement below
select p.product_id,
    IFNULL(
        ROUND(SUM(u.units * p.price)/ SUM(u.units), 2)
    ,0) as average_price
from Prices p 
LEFT JOIN UnitsSold u
        ON  p.product_id = u.product_id
        and u.purchase_date between p.start_date and p.end_date
GROUP BY p.product_id




