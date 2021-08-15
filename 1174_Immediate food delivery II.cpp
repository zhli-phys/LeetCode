with first_order as (
    Select customer_id, min(order_date) as first_date, min(customer_pref_delivery_date) as first_delivery_date
    From Delivery
    Group by customer_id
    Having first_date = first_delivery_date
)
Select Round((Select Count(Distinct customer_id) From first_order) 
             / (Select Count(Distinct customer_id) From Delivery) * 100, 2) as immediate_percentage