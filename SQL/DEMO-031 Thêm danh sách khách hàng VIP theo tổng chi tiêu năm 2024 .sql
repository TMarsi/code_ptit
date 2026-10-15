insert into VipCustomer (CustID ,CustomerName ,City,TotalSpent2024)
select c.CustID,c.CustomerName,c.City,sum(s.TotalAmount) as TotalSpent2024 
from Customer c
join SaleOrder s on c.CustID = s.CustID 
where s.OrderDate > '2024-01-01' and s.OrderDate <= '2024-12-31'
group by c.CustID,c.CustomerName,c.City
having sum(s.TotalAmount) >= 2000;