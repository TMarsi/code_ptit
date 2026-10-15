update SALEORDER
set Status = 'PAID'
where OrderID in(
  select OrderID
  from Payment
  where Status = 'PAID'
)