-- Last updated: 10/3/2026, 6:51:41 PM
# Write your MySQL query statement below
WITH RankedOrders as (
    SELECT *,
    RANK() OVER(PARTITION BY customer_id ORDER BY order_date ASC) as rnk
    FROM Delivery 
)
select 
    ROUND((
            AVG(order_date = customer_pref_delivery_date ) *100

    ),2) as immediate_percentage
FROM RankedOrders
WHERE rnk = 1
