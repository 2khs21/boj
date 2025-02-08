-- 코드를 입력하세요

# RANK 를 쓰지말고 limit 하는게 낫다.
# 가상테이블 없이 하는게 더 깔끔하네

SELECT I.NAME, I.DATETIME
FROM ANIMAL_INS I
LEFT OUTER JOIN ANIMAL_OUTS O ON I.ANIMAL_ID = O.ANIMAL_ID
where o.ANIMAL_ID is  NULL
order by datetime
limit 3