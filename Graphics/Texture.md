## 텍셀 / 픽셀

텍셀 : 3D 오브젝트의 기본 단위

픽셀 : 2D 오브젝트의 기본 단위, 그래픽 이미지의 한 점 

## 게임에서 사용하는 포멧 종류

BMP : 윈도우와 OS/2에서 기본으로 사용하는 그래픽 포맷 무손실, 32bit 지원, Rle 압축 가능

TGA : 24 비트 칼라 지원 32 비트 알파 채널 포함, 무손실, 32bit 지원, 여러 이미지, 텍스쳐의 원본 파일

PSD : 레이어, 채널, 패스 등 다량의 정보 저장 가능. 작업용으로 중요한 포맷, 무손실, 32bit 지원

PNG : indexed color(8bit) 사용가능. 효율이 높고 알파채널 사용가능/ 비손실, index/ RGBA 지원

## 밉맵

밉맵이란 원거리로 갈수록 작은 사이즈의 텍스쳐를 적용하는 방식 

밉맵핑(Mipmapping)은 앨리어싱 문제를 해결하기 위해 고안된 기술. 즉석에서 이미지를 다운 샘플링 하는대신, 레벨이라 불리는 일련의 사전 필터링된 이미지가 오프라인 또는 로딩 시간에 재생. 각 텍스쳐의 메모리 사용량을 33% .증가, 동적 장면의 퀄리티 증가 

## 텍스쳐 압축

Unity는 자동 포맷

PC용 이미지 압축 포맷

DDS(Direct Draw Surface)파일 포맷 : 

DirectX 기반의 텍스쳐 맵을 나타내기 위해 사용되는 이미지 형식. 손실대비 압축률 높음. 2D 이미지에서 밉맵/ 큐브맵 생성 가능/ 2의 제곱 승수 사이즈만 가능

BC (Block Compression) 포맷 :

PC에서만 주로 사용. BC1 ~ BC7까지 존재 



