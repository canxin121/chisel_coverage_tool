use cmds::parse_coverage_info;

pub mod types;
pub mod cmds;

#[cfg_attr(mobile, tauri::mobile_entry_point)]
pub fn run() {
    tauri::Builder::default()
        .plugin(tauri_plugin_opener::init())
        .invoke_handler(tauri::generate_handler![parse_coverage_info])
        .run(tauri::generate_context!())
        .expect("error while running tauri application");
}
