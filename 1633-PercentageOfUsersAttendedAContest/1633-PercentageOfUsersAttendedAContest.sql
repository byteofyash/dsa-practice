-- Last updated: 10/3/2026, 6:50:54 PM
# Write your MySQL query statement below
with contestStats as(
select contest_id,
    COUNT(r.user_id) * 100.0 / (SELECT COUNT(*) from Users) as raw_pct
from Register r
GROUP BY contest_id
)

select contest_id,
        ROUND(raw_pct, 2) as percentage
from contestStats 
GROUP BY contest_id
ORDER BY
    percentage DESC,
    contest_id ASC

