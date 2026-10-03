-- Last updated: 10/3/2026, 6:51:49 PM
# Write your MySQL query statement below
select distinct author_id as id
from Views
where  author_id = viewer_id
order by author_id ASC