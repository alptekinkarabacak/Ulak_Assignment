1.Sorunun cevabı Explanation of Secondary Node Edition isimli pdf dosyasında yazmaktadır.

2.Programı çalıştırmak için:

Yüklediğim Makefile yardımıyla make all yapılması yeterlidir.

Derleme sonrasında " sgnbAdditionRequest " " sgnbAdditionRequestAck " adında 2 adet binary çıktı dosyası oluşacaktır.
Önce " sgnbAdditionRequest " ardından yeni bir terminal penceresinde de " sgnbAdditionRequestAck " çalıştırılmalıdır.
Data gönderme işlemleri tamamlandığında, " sgnbAdditionRequest " penceresinde " SGNB Addition Request Message has been sent ", 
" sgnbAdditionRequestAck " terminalinde " SGNB Addition Request Acknowledge Message has been sent " mesajları gözükecektir.
Bir hata var sanırım byteları kaydırdım fakat bazı datalar gitmemiş.
Doxygen' e uygun temiz kod yazmaya çalıştım fakat, hatayı bulamadım. Aslında gelen dataları parse edip gelen bilgileri ekrana daha düzgün yazdırmak isterdim.

