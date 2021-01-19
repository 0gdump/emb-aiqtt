# Aiqtt 

## Описание

Газоанализатор с передачей значений по wifi + mqtt. Исходный код клиента расположен здесь: *TODO*.

## Схема

*TODO*

## Зависимости

*TODO*

## MQTT

Устройство выступает в роли mqtt брокера и не поддерживает режим клиента.

### Все доступные топики

При подключении устройство публикует актуальные данные в топики:

| Топик                    | Описание                       |
|--------------------------|--------------------------------|
| air/aiqtt/${id}/about    | Об устройстве                  |
| air/aiqtt/${id}/config   | Настройки устройства           |
| air/aiqtt/${id}/wifi     | Настройки WiFi                 |
| air/aiqtt/${id}/snapshot | Актуальные данные с датчиков   |

### Редактирование настроек

Для редактирования настроек публикуется JSON с одим или несколькими параметрами в топик.

**Пример**

Настройка дочки доступа WiFi. Публикация в топик air/aiqtt/${id}/wifi

```json
{
	"ap_ssid": "Modern AP",
	"ap_pass": "SecurityPassword"
}
```

### Подробное описание топиков

#### Об устройстве

Топик: air/aiqtt/${id}/about
Недоступен для редактирования

Содержит информацию об устройстве, прошивке.

**Пример**

```json
{
	"codename": "ProtoDev",
	"id": "a8e8",
	"version": "1901.21"
}
```

**Подробное описание**

| Параметр | Тип     | Описание                            |
|----------|---------|-------------------------------------|
| codename | String  | Кодовое имя устройства              |
| id       | String  | Уникальный идентификатор устройства |
| version  | String  | Текущая версия прошивки             |

#### Настройки устройства

Топик: air/aiqtt/${id}/config
Доступен для редактирования

Содержит актуальные настройки устройства.

**Пример**

```json
{
	"include_gps": false
}
```

**Подробное описание**

| Параметр    | Тип     |  Описание                                                         |
|-------------|---------|-------------------------------------------------------------------|
| include_gps | Boolean | Включать информацию о местоположении устройства в снапшот данных  |

#### Данные WiFi

Топик: air/aiqtt/${id}/wifi
Доступен для редактирования, параметры применяются после перезапуска.

Содержит данные для создания точки доступа или подключения к cуществующей wifi сети

**Пример**

```json
{
	"use_ap": true,
	"ap_ssid": "Aiqtt",
	"ap_pass": "12341234",
	"wifi_ssid": "",
	"wifi_pass": ""
}
```

**Подробное описание**

| Параметр  | Тип     | Описание                   |
|-----------|---------|----------------------------|
| use_ap    | Boolean | Использовать точку доступа |
| ap_ssid   | String  | SSID точки доступа         |
| ap_pass   | String  | Пароль точки доступа       |
| wifi_ssid | String  | SSID сети wifi             |
| wifi_pass | String  | Пароль сети wifi           |

#### Актуальные данные

Топик: air/aiqtt/${id}/snapshot
Недоступен для редактирования.

Содержит актуальные показания с датчиков.

**Пример**

```json
{
	"timestamp": 0,
	"gps_longitude": 37.618423,
	"gps_latitude": 55.751244,
	"gps_height": 0.0,
	"co2": 0.0,
	"humidity": 0.0,
	"lpg": 0.0,
	"methane": 0.0,
	"smoke": 0.0,
	"temperature": 0.0
}
```

**Подробное описание**

| Параметр      | Тип   | Измерения | Описание                           |
|---------------|-------|-----------|------------------------------------|
| timestamp     | Int   | Секунды   | Время с включения устройства       |
| gps_longitude | Float | -         | Долгота                            |
| gps_latitude  | Float | -         | Широта                             |
| gps_height    | Float | -         | Высота                             |
| co2           | Float | PPM       | Количество углекислого газа        |
| humidity      | Float | %         | Влажность воздуха                  |
| lpg           | Float | PPM       | Количество летучих углеводородов   |
| methane       | Float | PPM       | Метан                              |
| smoke         | Float | PPM       | Количество угарного газа в воздухе |
| temperature   | Float | °C        | Температура воздуха                |