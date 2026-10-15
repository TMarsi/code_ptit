select mh.TenHang,mh.MaCongTy,ncc.TenCongTy
from MATHANG mh
join NHACUNGCAP ncc on ncc.macongty = mh.macongty
order by mh.tenhang asc