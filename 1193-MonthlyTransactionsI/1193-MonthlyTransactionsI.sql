-- Last updated: 10/3/2026, 6:51:35 PM
# Write your MySQL query statement below
select
    date_format(trans_date,'%Y-%m') as month,
    country,  
   COUNT(id) as trans_count , 
   COUNT(CASE WHEN state= 'approved' THEN 1 END ) as approved_count ,

    SUM(amount) as trans_total_amount , 
    SUM(CASE WHEN state= 'approved' THEN amount ELSE 0 END ) as approved_total_amount 
from Transactions
GROUP BY month, country
