# Write your MySQL query statement below
select user_id, COUNT(Distinct(follower_id)) as followers_count
from Followers
GROUP BY user_id
ORDER BY user_id ASC;