With avg_quantity As (
    Select 
        Avg(quantity) As avg_quantity
    From
        OrdersDetails
    Group By
        order_id
)
Select
    order_id
From
    OrdersDetails
Group By
    order_id
Having 
    Max(quantity) > (Select Max(avg_quantity) From avg_quantity)