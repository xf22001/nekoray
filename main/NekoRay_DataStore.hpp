// DO NOT INCLUDE THIS

namespace NekoRay {

    QString FindCoreAsset(const QString &name);

    class Routing : public JsonStore {
    public:
        QString direct_ip;
        QString direct_domain;
        QString proxy_ip;
        QString proxy_domain;
        QString block_ip;
        QString block_domain;
        QString custom = "{\"rules\": []}";

        explicit Routing(int preset = 0);

        [[nodiscard]] QString toString() const;

        static QStringList List();

        static void SetToActive(const QString &name);
    };

    class ExtraCore : public JsonStore {
    public:
        QString core_map;

        explicit ExtraCore();

        [[nodiscard]] QString Get(const QString &id) const;

        void Set(const QString &id, const QString &path);

        void Delete(const QString &id);
    };

    class DataStore : public JsonStore {
    public:
        // Running

        QString core_token;
        int core_port = 19810;
        int started_id = -1919;
        bool core_running = false;
        bool core_prepare_exit = false;
        int running_spmode = NekoRay::SystemProxyMode::DISABLE;
        bool need_keep_vpn_off = false;
        QStringList ignoreConnTag = {};

        Routing *routing = new Routing;
        int imported_count = 0;
        bool refreshing_group_list = false;
        int resolve_count = 0;

        // Flags
        bool flag_use_appdata = false;
        bool flag_many = false;
        bool flag_tray = false;
        bool flag_debug = false;

        // Saved

        // Misc
        QString log_level = "warning";
        QString test_url = "http://cp.cloudflare.com/";
        int test_concurrent = 5;
        int traffic_loop_interval = 500;
        bool connection_statistics = false;
        int current_group = 0; // group id
        int mux_cool = -8;
        QString theme = "0";
        QString v2ray_asset_dir = "";
        int language = 0;
        QString mw_size = "";
        bool check_include_pre = false;
        QString system_proxy_format = "";

        // Subscription
        QString user_agent = "Nekoray/1.0 (Prefer Clash Format)";
        bool sub_use_proxy = false;
        bool sub_clear = false;
        bool sub_insecure = false;

        // Security
        bool insecure_hint = true;
        bool skip_cert = false;

        // Remember
        int remember_spmode = NekoRay::SystemProxyMode::DISABLE;
        int remember_id = -1919;
        bool remember_enable = false;

        // Socks & HTTP Inbound
        QString inbound_address = "127.0.0.1";
        int inbound_socks_port = 2080; // or Mixed
        int inbound_http_port = -2081;
        QString custom_inbound = "{\"inbounds\": []}";

        // DNS
        QString remote_dns = "https://8.8.8.8/dns-query";
        QString direct_dns = "localhost";
        bool dns_routing = true;
        bool enhance_resolve_server_domain = false;

        // Routing
        bool fake_dns = false;
        QString domain_strategy = "AsIs";
        QString outbound_domain_strategy = "AsIs";
        int sniffing_mode = SniffingMode::FOR_ROUTING;
        int domain_matcher = DomainMatcher::MPH;
        QString custom_route_global = "{\"rules\": []}";
        QString active_routing = "Default";

        // VPN
        int vpn_implementation = 0;
        int vpn_mtu = 9000;
        bool vpn_ipv6 = false;
        bool vpn_hide_console = false;
        bool vpn_strict_route = false;
        QString vpn_bypass_process = "";
        QString vpn_bypass_cidr = "";

        // Hotkey
        QString hotkey_mainwindow = "";
        QString hotkey_group = "";
        QString hotkey_route = "";

        // Other Core
        ExtraCore *extraCore = new ExtraCore;

        DataStore();

        void UpdateStartedId(int id);
    };

    extern DataStore *dataStore;

    inline int coreType = NekoRay::CoreType::V2RAY;

} // namespace NekoRay

#define IS_NEKO_BOX (NekoRay::coreType == NekoRay::CoreType::SING_BOX)
#define ROUTES_PREFIX_NAME QString(IS_NEKO_BOX ? "routes_box" : "routes")
#define ROUTES_PREFIX QString(ROUTES_PREFIX_NAME + "/")
