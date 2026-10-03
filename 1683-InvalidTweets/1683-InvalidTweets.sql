-- Last updated: 10/3/2026, 6:50:45 PM
# Write your MySQL query statement below
select tweet_id
from Tweets
where char_length(content) > 15
