# Write your MySQL query statement below
select p.product_name, p1.year , p1.price from 
Product p
 JOIN  Sales p1
ON p.product_id=p1.product_id;
