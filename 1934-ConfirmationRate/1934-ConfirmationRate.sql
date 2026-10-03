-- Last updated: 10/3/2026, 6:50:18 PM
# Write your MySQL query statement below
select s.user_id, 
        ROUND(AVG(
            COALESCE (
                CASE 
                WHEN c.action = 'confirmed' 
                THEN 1 ELSE 0 
                END )),2) as  confirmation_rate 
from Signups s
LEFT JOIN Confirmations c
        ON s.user_id = c.user_id
GROUP BY  s.user_id