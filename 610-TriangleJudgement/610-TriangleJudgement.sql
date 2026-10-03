-- Last updated: 10/3/2026, 6:53:28 PM
# Write your MySQL query statement below
select
   x  , y  , z  , 
    IF(x+y > z AND x+z > y AND y+z> x, 'Yes', 'No') AS triangle
from Triangle

  