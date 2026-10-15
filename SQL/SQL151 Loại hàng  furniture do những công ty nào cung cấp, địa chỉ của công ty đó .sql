select lh.TenLoaiHang,ncc.TenCongTy,ncc.DiaChi
from NHACUNGCAP ncc
join MATHANG mh on ncc.MaCongTy = mh.MaCongTy
join LOAIHANG lh on lh.MaLoaiHang = mh.MaLoaiHang
where TenLoaiHang = 'furniture'