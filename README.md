# 🏠 IoT System Programming & Application (C Language)

이 저장소는 Raspberry Pi 환경에서 C언어를 이용해 다양한 센서와 액추에이터를 제어하고, 이를 결합하여 실생활 응용 시스템을 구축한 실습 및 프로젝트 코드를 포함하고 있습니다.

---
## 📅 Project Information

진행 시기: 3학년 1학기 (사물인터넷 수업)

날짜: 2024.03 ~ 2024.06

---
## 📂 디렉토리 구조 (Directory Structure)

| 대분류 | 폴더명 | 설명 |
| --- | --- | --- |
| Class Code | `class-code/` | 수업 시간에 학습한 개별 센서 및 컴포넌트 제어 기초 코드 |
| Personal Project | `project_bbw/` | 실습 코드를 바탕으로 여러 센서를 결합해 구현한 응용 프로젝트 |

---

## 🛠️ 실습 내용 (Class-Code)

각 컴포넌트의 하드웨어 특성을 이해하고, GPIO 및 ADC 라이브러리를 활용해 제어 로직을 구현했습니다.

### 1) 센서 입력 (Input Sensors)
- **환경 감지**: `dht11`(온습도), `dust`(미세먼지), `gas`(가스), `cds`(조도), `pir`(인체 감지)
- **거리 및 물리량**: `hc-sr04`(초음파 거리), `psd`(적외선 거리), `sound`(소리 감지)
- **스위치 및 모듈**: `button`(입력 버튼), `photoInterrupter`(비접촉 스위치)

### 2) 출력 및 액추에이터 (Output & Actuators)
- **디스플레이**: `fnd`(7-Segment), `textlcd`(문자 LCD)
- **구동 장치**: `motor`(서보/DC 모터), `stepmotor`(스테핑 모터), `fan`(모터 팬)
- **알림 도구**: `led`(기본 점등), `buzzer`(수동/능동 부저)

---

## 🚀 개인 프로젝트 (Project BBW)

학습한 기초 코드를 결합하여 특정 목적을 가진 시스템으로 확장한 결과물입니다.

### 🔔 스마트 알람 및 정보 시스템 (`alarm`, `sleepdata`)
- **Smart Alarm**: 버튼 입력으로 설정을 제어하고, FND 디스플레이와 부저를 결합한 알람 시스템입니다.
- **Sleep Data**: 초음파 센서와 조도 센서 등을 활용해 수면 중 움직임/환경 데이터를 수집하고 LCD로 출력합니다.

### 🔥 화재 감지 및 자동 제어 시스템 (`fire`, `dht11_motor`)
- **Fire Detection**: 가스/화재 센서(ADC)와 온습도 데이터를 실시간으로 모니터링하여 위험 시 LED와 경보를 작동시킵니다.
- **Auto Fan Control**: 설정된 온도/습도 임계값에 따라 팬 모터를 자동 구동하여 환경을 유지하는 제어 시스템입니다.

---

## 🔧 개발 환경 (Environment)
- **Hardware**: Raspberry Pi 3/4
- **Language**: C
- **Compiler**: GCC
- **Library**: WiringPi (GPIO 제어)

---

## 🏁 실행 방법 (How to Run)

각 디렉토리의 `Makefile`을 이용해 컴파일 후 실행할 수 있습니다.

```bash
# 예시: 화재 감지 프로젝트 실행
cd project_bbw/fire
make
sudo ./main
```

