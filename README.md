LAPORAN RESMI
SISTEM OPERASI



KELOMPOK : C1

**Oleh:**

Yuki Yanuar Ratna

05111740000023

Adnan Erlangga Raharja

05111740000100

**Asisten Pembimbing:**

M.Faris Didin Andiyar

5115100118

Departemen Infomatika

Fakultas Teknologi Informasi dan Komunikasi

Institut Teknologi Sepuluh Nopember (ITS)

Surabaya

2019

**Soal**

Buatlah program C yang menyerupai crontab menggunakan daemon dan thread. Ada sebuah file crontab.data untuk menyimpan config dari crontab. Setiap ada perubahan file tersebut maka secara otomatis program menjalankan config yang sesuai dengan perubahan tersebut tanpa perlu diberhentikan. Config hanya sebatas * dan 0-9 (tidak perlu /,- dan yang lainnya)

**Jawaban :**

```
char caesar[] = {"qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0"};
char encrypt[1000], decrypt[1000];

void enc(char arr[]);
void dec(char arr[]);

void enc(char arr[])
{
	int n, i, ch;
	for(n = 0; arr[n] != '\0'; ++n)
	{
		ch = arr[n];

		if(ch == '/') continue;

		for(i = 0; i < strlen(caesar); i++)
		{
			if(ch == caesar[i]) break;
		}
		
		i = i + 17;
		if(i > 93) i = i - strlen(caesar);

		arr[n] = caesar[i];
	}
}

void dec(char arr[])
{
	int n, i, ch;
	for(n = 0; arr[n] != '\0'; ++n)
	{
		ch = arr[n];

		if(ch == '/') continue;

		for(i = 0; i < strlen(caesar); i++)
		{
			if(ch == caesar[i]) break;
		}
		
		i = i - 17;
		if(i < 0) i = i + strlen(caesar);

		arr[n] = caesar[i];
	}
}
```

**Langkah-Langkah**

1. Dapatkan waktu sekarang
2. Ambil data crontab dari crontab.data
3. Ambil konfigurasi crontabnya saja, seperti 1 1 1 1 1
4. Bandingkan dengan waktu sekarang
5. Jika sama jalankan file

**Kendala Yang Dialami**

Belum membuat thread 
