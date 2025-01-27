# Write your MySQL query statement below
select MAX(num ) as num 
From MyNumbers 
WHERE NUM IN(
    select num 
    from MyNumbers
    group by num
    having count(*)=1
);