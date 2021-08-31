Select
    name,
    IfNull(Sum(rest), 0) As rest,
    IfNull(Sum(paid), 0) As paid,
    IfNull(Sum(canceled), 0) As canceled,
    IfNull(Sum(refunded), 0) As refunded
From 
    Product
Left Join
    Invoice
On
    Invoice.product_id = Product.Product_id
Group By
    Product.product_id
Order By
    name