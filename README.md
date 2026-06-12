# ConsoleMVC — C++ Console MVC Skeleton (PoC)

콘솔 전용 C++ MVC 아키텍처 PoC 프로젝트입니다.  
**Task Manager** 예제를 통해 Model / View / Controller 의 역할 분리와 패키지 구조를 시연합니다.

---

## 빌드 환경

| 항목 | 값 |
|------|-----|
| IDE | Visual Studio 2022 (v145 toolset) |
| 빌드 시스템 | MSBuild |
| C++ 표준 | C++20 |
| 플랫폼 | Win32 / x64 |

---

## 프로젝트 구조

```
ConsoleMVC/
├── ConsoleMVC.slnx              # Solution 파일
├── ConsoleMVC.vcxproj           # MSBuild 프로젝트
├── ConsoleMVC.vcxproj.filters   # VS 솔루션 탐색기 폴더 구조
├── README.md
└── src/
    ├── main.cpp                 # 진입점 — Application::run() 호출
    │
    ├── Core/
    │   ├── Application.h        # MVC 3요소 소유 + 메인 루프
    │   └── Application.cpp
    │
    ├── Model/                   # [데이터 & 비즈니스 로직]
    │   ├── IModel.h             # 모델 인터페이스 (확장 기반)
    │   ├── Task.h               # 도메인 엔티티 (데이터 구조체)
    │   ├── TaskModel.h
    │   └── TaskModel.cpp        # CRUD 로직, View/Controller 의존 없음
    │
    ├── View/                    # [콘솔 렌더링 전담]
    │   ├── IView.h              # render() 순수 가상 함수
    │   ├── TaskView.h
    │   └── TaskView.cpp         # 출력·입력 프롬프트, 비즈니스 로직 없음
    │
    └── Controller/              # [입력 처리 & 조정]
        ├── IController.h        # handleInput() / isRunning() 인터페이스
        ├── TaskController.h
        └── TaskController.cpp   # 사용자 입력 → Model 조작 → View 갱신
```

---

## MVC 역할 분리

```
사용자 입력
     │
     ▼
┌─────────────┐   조작   ┌─────────────┐
│ Controller  │ ───────▶ │    Model    │
│ (입력 처리)  │          │ (데이터·로직)│
└─────────────┘          └─────────────┘
     │                         │
     │ 렌더링 요청               │ 데이터 제공 (const ref)
     ▼                         ▼
┌─────────────────────────────────┐
│              View               │
│         (콘솔 출력 전담)          │
└─────────────────────────────────┘
```

- **Model** — View / Controller를 전혀 알지 못함. 순수 데이터와 로직만.  
- **View** — `const TaskModel&` 참조로 읽기 전용 접근. 데이터 가공 없음.  
- **Controller** — Model을 변경한 뒤 View의 `render()`를 간접 트리거(루프 구조로 자동 갱신).

---

## 빌드 방법

### Visual Studio GUI

1. `ConsoleMVC.slnx` 더블클릭으로 Visual Studio 실행
2. 상단 구성: `Debug | x64` (또는 원하는 구성 선택)
3. **빌드 > 솔루션 빌드** (`Ctrl+Shift+B`)
4. **디버그 > 디버깅하지 않고 시작** (`Ctrl+F5`)

### MSBuild CLI

```bat
:: Visual Studio 2022 Developer Command Prompt 에서 실행
cd C:\Users\User\Desktop\Test\ConsoleMVC

:: Debug x64 빌드
msbuild ConsoleMVC.vcxproj /p:Configuration=Debug /p:Platform=x64

:: Release x64 빌드
msbuild ConsoleMVC.vcxproj /p:Configuration=Release /p:Platform=x64

:: 실행
x64\Debug\ConsoleMVC.exe
```

---

## 실행 예시

```
========================================
   ConsoleMVC - Task Manager (PoC)
========================================

+----------------------------------+
|  Task List (  0 items)           |
+----------------------------------+
|  (empty)                         |
+----------------------------------+

  [1] Add    [2] Complete    [3] Delete    [0] Quit
  > 1
  Task title: Buy groceries
  [OK] Task added.

+----------------------------------+
|  Task List (  1 items)           |
+----------------------------------+
|  [  1] [ ] Buy groceries         |
+----------------------------------+

  [1] Add    [2] Complete    [3] Delete    [0] Quit
  > 2
  Task ID to complete: 1
  [OK] Task #1 marked as done.

  ...

  > 0

Goodbye!
```

---

## 새 도메인 추가 방법 (확장 가이드)

새 기능(예: `Note` 관리)을 추가할 때 MVC 구조에 맞게 파일을 추가합니다.

1. `src/Model/Note.h` — 엔티티 구조체
2. `src/Model/NoteModel.h/.cpp` — IModel 상속, 비즈니스 로직
3. `src/View/NoteView.h/.cpp` — IView 상속, 콘솔 렌더링
4. `src/Controller/NoteController.h/.cpp` — IController 상속, 입력 처리
5. `Application`에서 세 객체를 생성해 루프에 연결
6. `.vcxproj` 및 `.vcxproj.filters`에 새 파일 항목 추가
