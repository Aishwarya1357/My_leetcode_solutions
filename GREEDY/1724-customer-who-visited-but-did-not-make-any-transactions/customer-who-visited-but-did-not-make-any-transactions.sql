# Write your MySQL query statement below
select customer_id,
COUNT(*) AS count_no_trans
FROM Visits V
LEFT JOIN 
Transactions t
ON  V.visit_id=t.visit_id
WHERE transaction_id is NULL
GROUP BY customer_id;