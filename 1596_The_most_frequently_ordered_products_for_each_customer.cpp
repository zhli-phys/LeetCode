WITH ranks AS (
    SELECT 
        customer_id, product_id, 
        RANK() OVER (PARTITION BY customer_id ORDER BY COUNT(*) DESC) AS ranks
    FROM 
        Orders
    GROUP BY
        customer_id, product_id
)
SELECT 
    ranks.customer_id, ranks.product_id, Products.product_name
FROM
    ranks
JOIN 
    Products
ON
    ranks.product_id = Products.product_id
WHERE
    ranks.ranks = 1