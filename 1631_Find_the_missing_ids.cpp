With recursive seq As (
    Select 1 As ids
    Union All
    Select ids + 1 
    From seq
    Where ids < (Select Max(customer_id) From customers)
)
Select 
    ids 
From 
    seq
Where
    ids Not In (Select customer_id From customers)