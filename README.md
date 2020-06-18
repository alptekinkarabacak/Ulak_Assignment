1.Sorunun cevabı Explanation of Secondary Node Edition isimli pdf dosyasında yazmaktadır.

2.Programı çalıştırmak için:

Yüklediğim Makefile yardımıyla make all yapılması yeterlidir.

Derleme sonrasında " sgnbAdditionRequest ", " sgnbAdditionRequestAck " adında 2 adet binary çıktı dosyası oluşacaktır.
Önce " sgnbAdditionRequest " ardından yeni bir terminal penceresinde de " sgnbAdditionRequestAck " çalıştırılmalıdır.
./sgnbAdditionRequest
./sgnbAdditionRequestAck
Data gönderme işlemleri tamamlandığında, " sgnbAdditionRequest " penceresinde " SGNB Addition Request Message has been sent ", 
" sgnbAdditionRequestAck " terminalinde " SGNB Addition Request Acknowledge Message has been sent " mesajları gözükecektir.
Bu noktada sanırım bir hata var, byteları kaydırdım fakat bazı dataların, " 0 " atanmadığı halde " 0 " olduğunu görüyorum. Genel olarak Doxygen' e uygun, temiz kod yazmaya çalıştım. Son olarak da gelen datalar parse edilip ekrana formatlı yazdırılsa daha düzgün olabilir.
