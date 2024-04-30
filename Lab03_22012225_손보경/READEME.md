# MFC 프로그램 구조
## 파일 읽어 화면에 출력하기
### Simple 예제를다음과같이수정하시오. 
### CSimpleApp::InitInstance() 함수에서 텍스트 파일을 읽어 파일 내 문자열을 CString 클래스 객체로 보관한다. 그리고, 해당 문자열을 CChildView::OnPaint() 함수에서 화면에 출력한다. 


#### 참고및제한사항
- 텍스트 파일은 유니코드가 아닌 ANSI 문자열을 포함한것으로 가정한다. 
- 파일입출력은 ::fopen()같은 C 런타임라이브러리이용
- 텍스트 화면 출력은 CDC::TextOut() 또는 CDC::DrawText() 함수 이용
- 파일이름은 “sample.txt”로 고정하고, 파일 내용은 1024 byte를 넘지 않는다고 가정
