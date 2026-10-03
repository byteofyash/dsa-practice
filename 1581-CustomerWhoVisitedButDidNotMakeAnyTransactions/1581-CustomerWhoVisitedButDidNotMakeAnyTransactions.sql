-- Last updated: 10/3/2026, 6:50:59 PM
# Write your MySQL query statement below
select v.customer_id, COUNT(v.visit_id) as count_no_trans
from Visits v 
LEFT JOIN Transactions t
       ON v.visit_id = t.visit_id 
WHERE t.transaction_id IS NULL
GROUP BY v.customer_id