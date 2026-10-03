-- Last updated: 10/3/2026, 6:51:30 PM
# Write your MySQL query statement below

select query_name, 
        ROUND(AVG(rating/position),2) as quality,
        ROUND((
            AVG (rating < 3) * 100
        ),2) as poor_query_percentage
from Queries
group by query_name
