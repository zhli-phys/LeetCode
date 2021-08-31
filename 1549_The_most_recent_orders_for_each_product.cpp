With orders_with_rank As (
    Select
        order_id, order_date, product_id,
        Rank() Over (Partition By product_id Order By order_date Desc) As rnk
    From 
        Orders
),
latest_orders As (
    Select
        order_id, order_date, product_id
    From 
        orders_with_rank
    Where
        rnk = 1
)
Select 
    product_name, latest_orders.product_id, order_id, order_date
From 
    latest_orders
Join
    Products
On
    latest_orders.product_id = Products.product_id
Order By
    product_name, latest_orders.product_id, order_id












With latest_orders As (
    Select
        order_id, order_date, product_id,
        Rank() Over (Partition By product_id Order By order_date Desc) As rnk
    From 
        Orders
)
Select 
    product_name, latest_orders.product_id, order_id, order_date
From 
    latest_orders
Join
    Products
On
    latest_orders.product_id = Products.product_id
Where
    latest_orders.rnk = 1
Order By
    product_name, latest_orders.product_id, order_id














With latest_date As (
    Select
        product_id, Max(order_date) As latest_date
    From
        Orders
    Group By
        product_id
),
latest_orders As (
    Select
        order_id, order_date, Orders.product_id
    From 
        Orders
    Join
        latest_date
    On
        Orders.product_id = latest_date.product_id
        And Orders.order_date = latest_date.latest_date
)
Select 
    product_name, latest_orders.product_id, order_id, order_date
From 
    latest_orders
Join
    Products
On
    latest_orders.product_id = Products.product_id
Order By
    product_name, latest_orders.product_id, order_id